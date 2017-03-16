t = input()

def fact(n):
    prod = 1
    while n > 1:
        prod = (prod * n) % 1000000007
        n -= 1
    return prod

def stripped(car):
    prev = car[0]
    filt = []
    for i in xrange(1, len(car)):
        if car[i] == prev:
            continue
        else:
            filt.append(prev)
            prev = car[i]
    filt.append(prev)
    return filt

def by_length(li):
    one, two, rest = [], [], []
    for car in li:
        le = len(car)
        if le == 1:
            one.append(car)
        elif le == 2:
            two.append(car)
        else:
            rest.append(car)
    return one, two, rest
    
def check_big_join(single, joiner, big_joiner):
    for jo in big_joiner:
        middle = jo[1:-1]
        for ch in middle:
            # if it appears anywhere else, it's not doable
            if jo.count(ch) > 1:
                return False
            for car in cars:
                if ch in car and car != jo:
                    return False
    return True
    
def make_disjoint(n):
    return [-1] * n
    
def find(s, i):
    if s[i] < 0:
        return i
    s[i] = find(s, s[i])
    return s[i]
    
def union(s, i, j):
    r1, r2 = find(s, i), find(s, j)
    if r1 == r2:
        return
    if s[r1] < s[r2]:
        s[r2] += s[r1]
        s[r1] = r2
    else:
        s[r1] += s[r2]
        s[r2] = r1
    
from string import ascii_lowercase
    
def num_single_ways(single):
    single = [ car[0] for car in single ]
    counts = [single.count(ch) for ch in ascii_lowercase]
    total = 1
    for count in counts:
        total = (total * fact(count)) % 1000000007
    return total
    
def num_joiner_orderings(joiner):
    # find paths
    verts = make_disjoint(c)
    in_degree = [0] * c
    out_degree = [0] * c
    for start, end in joiner:
        # All are usable if every edge connects set (no cycles exist)
        # and if degree is at most 2 for any vertex
        m1, m2 = mapping[start], mapping[end]
        if find(verts, m1) == find(verts, m2):
            return 0
        union(verts, m1, m2)
        out_degree[m1] += 1
        if out_degree[m1] > 1:
            return 0
        in_degree[m2] += 1
        if in_degree[m2] > 1:
            return 0
    # number paths = vertices with 1 in degree and 0 out degree
    # or 0 in and out degree
    paths = 0
    for i in range(c):
        if in_degree[i] == 1 and out_degree[i] == 0:
            paths += 1
        if in_degree[i] == 0 and out_degree[i] == 0:
            paths += 1
    return fact(paths)
    
            
# Represent as a graph
# joiner = an edge
# big joiner = an edge with some weirdness on top
# problem then becomes # of hamiltonian
    
# Need to know where letters occur in car
# A joiner: forces the ordering of some letters

# Idea: First generate letter ordering
# Then multiply by ways for each letter

# Getting letter ordering: letter can appear at end of joiner,
# and at start of joiner, but not both
# and only one or the other...    
import itertools
def brute_force(cars):
    cars = [''.join(car) for car in cars]
    total = 0
    for perm in itertools.permutations(cars):
        s = "".join(perm)
        seen = set()
        prev = s[0]
        valid = True
        for i in xrange(1, len(s)):
            if s[i] == prev:
                continue
            seen.add(prev)
            if s[i] in seen:
                valid = False
                break
            prev = s[i]
        total += valid
    return total

for case in xrange(1, t+1):
    n = input()
    cars = [stripped(car) for car in raw_input().split()]
    #print "Case #%d: %d" % (case, brute_force(cars))
    #continue
    single, joiner, big_joiner = by_length(cars)
    valid = check_big_join(single, joiner, big_joiner)
    if not valid:
        print "Case #%d: %d" % (case, 0)
        continue
        
    # reduce big joiners
    for car in big_joiner:
        if car[0] == car[-1]:
            # not doable
            valid = False
            break
        else:
            joiner.append([car[0], car[-1]])
            
    if not valid:
        print "Case #%d: %d" % (case, 0)
        continue
    mapping = dict()
    reverse = dict()
    c = 0
    for start, end in joiner:
        if start not in mapping:
            mapping[start] = c
            reverse[c] = start
            c += 1
        if end not in mapping:
            mapping[end] = c
            reverse[c] = end
            c += 1
    for car in single:
        ch = car[0]
        if ch not in mapping:
            mapping[ch] = c
            reverse[c] = ch
            c += 1
    all = mapping.keys()
    # find ways to order joiner
    total = (num_joiner_orderings(joiner) * num_single_ways(single)) % 1000000007
    print "Case #%d: %d" % (case, total)