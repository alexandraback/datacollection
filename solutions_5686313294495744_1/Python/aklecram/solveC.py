import sys
from multiprocessing import Pool

# Add git repository with helpers to path
# The repo is publicly available at git@github.com:marcelka/cocoli.git
sys.path.append("/home/marcelka/projects/cocoli/")

def run(pool=None): # {{{
    inp=sys.argv[1]
    outp="%s.out" % inp.split(".")[0]

    with open(inp, 'r') as _file, open(outp, 'w') as out:
        _cases = int(_file.readline())
        arguments = []
        for _case in range(_cases):
            n = int(_file.readline())
            lines = []
            for i in range(n):
                lines.append(_file.readline()[:-1])
            arguments.append((_case + 1, (n, lines)))

        if pool == None:
            results = list(map(solve_wrapper, arguments))
        else:
            results = sorted(
                list(pool.imap_unordered(solve_wrapper, arguments)),
                key=lambda r: r[0])
        
        for _case, result in results:
            out.write("Case #%s: %s\n" % (_case, result))

def solve_wrapper(args):
    case_no, _args = args
    print("Solving case #%s" %(case_no))
    return (case_no, solve(*_args))
# }}}

def solve_small(n, lines):
    result = 0
    fmt = '{0:0' + ("%s" % n) + 'b}'
    for i in range(2**n):
        can_be = True
        originals = fmt.format(i)
        words1 = set()
        words2 = set()
        for j in range(n):
            if originals[j] == "1":
                w1, w2 = lines[j].split(" ")
                words1.add(w1)
                words2.add(w2)
        for j in range(n):
            if originals[j] == "0":
                w1, w2 = lines[j].split(" ")
                if w1 not in words1:
                    can_be = False
                if w2 not in words2:
                    can_be = False
        if can_be:
            result = max(result, originals.count("0"))
    return result

# real[w] = set of words
# fake[w] = set of words
def augment(words1, words2, real, fake):
    def move_to_fake(w1, w2):
        real[w1].remove(w2)
        real[w2].remove(w1)
        fake[w1].add(w2)
        fake[w2].add(w1)

    def move_to_real(w1, w2):
        real[w1].add(w2)
        real[w2].add(w1)
        fake[w1].remove(w2)
        fake[w2].remove(w1)

    todo = []
    visited = {}

    for w in words2:
        if len(real[w]) > 1:
            todo.append(w)
            visited[w] = None

    while True:
        if len(todo) == 0:
            return False
        w = todo.pop() # pozor hlbka/sirka?
        if w in words1:
            if len(real[w]) > 1:
                #print(visited)
                #print(w, visited[w], real)
                move_to_fake(w, visited[w])
                w2 = visited[w]
                while visited[w2] != None:
                    w1 = visited[w2]
                    w22 = visited[w1]
                    move_to_real(w2, w1)
                    move_to_fake(w1, w22)
                    w2 = w22
                return True
            for w2 in fake[w]:
                if w2 not in visited:
                    todo.append(w2)
                    visited[w2] = w
        if w in words2:
            for w1 in real[w]:
                if w1 not in visited:
                    todo.append(w1)
                    visited[w1] = w


from collections import defaultdict

def solve_large(n, lines):
    real = defaultdict(set)
    fake = defaultdict(set)
    words1 = set()
    words2 = set()
    for l in lines:
        w1, w2 = l.split(" ")
        w1 += "1"
        w2 += "2"
        words1.add(w1)
        words2.add(w2)
        real[w1].add(w2)
        real[w2].add(w1)

    can_continue = True
    while can_continue:
        can_continue = augment(words1, words2, real, fake)
    return sum(len(fake[w]) for w in fake) // 2

def solve(n, lines):
    #return solve_small(n, lines)
    return solve_large(n, lines)

run()

#import random
#lines = []
#for i in range(1000):
#    w1 = "A" * random.randint(1, 1000)
#    w2 = "A" * random.randint(1, 1000)
#    line = w1 + " " + w2
#    if line not in lines:
#        lines.append(line)
#print(len(lines))
#print(solve(len(lines), lines))

#run(Pool(4))
