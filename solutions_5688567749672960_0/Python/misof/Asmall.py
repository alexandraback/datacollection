from queue import Queue

Q = Queue()
dist = {}
dist[1] = 1
Q.put(1)

done = set()
done.add(1)

while len(done) < 10**6:
    kde = Q.get()
    kam1 = kde+1
    kam2 = int( str(kde)[::-1] )
    for kam in [kam1,kam2]:
        if kam in dist: continue
        dist[kam] = dist[kde] + 1
        if kam <= 10**6:
            done.add(kam)
        Q.put(kam)

T = int(input())
for t in range(1,T+1):
    print('Case #{}: {}'.format(t,dist[int(input())]))
