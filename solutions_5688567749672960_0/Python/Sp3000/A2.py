import heapq

limit = 1000000

heap = [(1, 1)]
solutions = [0]*(limit + 1)

while heap:
    times, n = heapq.heappop(heap)

    if n <= limit and not solutions[n]:
        solutions[n] = times
        heapq.heappush(heap, (times+1, n+1))
        rev = int(str(n)[::-1].lstrip("0"))
        heapq.heappush(heap, (times+1, rev))
        

with open("A-small-attempt0.in") as infile:
    with open("A.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases + 1):
            n = int(next(infile))

            print("Case #{}: {}".format(case, solutions[n]), file=outfile)

