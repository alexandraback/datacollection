t = int(raw_input())

all_pairs = dict()

def search_range(a, b):
    global all_pairs
    for i in range(a, b):
        all_pairs[i] = []
        n = str(i)
        for j in range(1, len(n)):
            new_n_j = int(n[j:] + n[0:j])
            if new_n_j > i and new_n_j <= b:
                all_pairs[i].append(new_n_j)

search_range(1, 9)
search_range(10, 99)
search_range(100, 999)
search_range(1000, 9999)
search_range(10000, 99999)
search_range(100000, 999999)
search_range(1000000, 2000000)

for tt in range(t):
    (a, b) = map(int, raw_input().split(' '))
    sol = 0

    for i in range(a, b):
        n = str(i)
        pairs = dict()
        for j in all_pairs[i]:
            if j > i and j <= b:
                pairs[j] = 1
        sol = sol + len(pairs)
    print "Case #%d: %d" % (tt + 1, sol)



