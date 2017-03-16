import collections

T = int(raw_input())

M = 1000000007

class DisjointSet(object):

    def __init__(self):
        self.leader = {} # maps a member to the group's leader
        self.group = {} # maps a group leader to the group (which is a set)

    def add(self, a, b):
        leadera = self.leader.get(a)
        leaderb = self.leader.get(b)
        if leadera is not None:
            if leaderb is not None:
                if leadera == leaderb: return # nothing to do
                groupa = self.group[leadera]
                groupb = self.group[leaderb]
                if len(groupa) < len(groupb):
                    a, leadera, groupa, b, leaderb, groupb = b, leaderb, groupb, a, leadera, groupa
                groupa |= groupb
                del self.group[leaderb]
                for k in groupb:
                    self.leader[k] = leadera
            else:
                self.group[leadera].add(b)
                self.leader[b] = leadera
        else:
            if leaderb is not None:
                self.group[leaderb].add(a)
                self.leader[a] = leaderb
            else:
                self.leader[a] = self.leader[b] = a
                self.group[a] = set([a, b])

def count_paths(start, adj, seen):
    if seen[start]:
        return 1, 0
    if (not adj[start]) or (list(adj[start]) == [start]):
        return 1, 1

    seen[start] = True
    counts = []
    m_lens = []
    for i in adj[start]:
        if i == start:
            continue
        count, m_len = count_paths(i, adj, seen)
        counts.append(count)
        m_lens.append(m_len)
    seen[start] = False
    m = max(m_lens)
    c = sum(counts[i] for i in range(len(counts)) if m_lens[i] == m)
    # print start, adj[start], counts, m_lens

    return c, 1+m

def factorial(n):
    if n <= 1:
        return 1
    return (n * factorial(n-1)) % M

for t in range(1, T+1):
    N = int(raw_input())

    start_with = collections.defaultdict(list)
    end_with = collections.defaultdict(list)
    adj = collections.defaultdict(set)
    seen_chars = set()
    ds = DisjointSet()
    zero = False
    words = raw_input().split()
    for i, w in enumerate(words):
        start_with[w[0]].append(i)
        end_with[w[-1]].append(i)
        if w[0] in seen_chars or w[-1] in seen_chars:
            # print 'zero'
            zero = True
        for i in range(1, len(w)-1):
            if w[i] != w[i-1] and w[i] in seen_chars:
                # print 'zero'
                zero = True
            elif w[i] != w[0] and w[i] != w[-1]:
                seen_chars.add(w[i])

    for i, w in enumerate(words):
        ds.add(i,i)
        for j in end_with[w[0]]:
            adj[j].add(i)
            ds.add(j,i)
        for j in start_with[w[-1]]:
            adj[i].add(j)
            ds.add(i,j)

    if zero or not ds.group:
        print 'Case #{}: 0'.format(t)
        continue

    res = 1

    for _, group in ds.group.iteritems():
        count = 0
        for i in group:
            seen = collections.defaultdict(bool)
            c, m = count_paths(i, adj, seen)
            if m == len(group):
                count += c
                count = count % M
        res *= count
        res = res % M

    # print ds.group
    res *= factorial(len(ds.group))

    print 'Case #{}: {}'.format(t, res)
