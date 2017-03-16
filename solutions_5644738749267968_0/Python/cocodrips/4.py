

def solve(n, M, As, Bs):
    As.sort()
    Bs.sort()

    pointA = 0

    a, b = 0, 0
    while a < M:
        if As[a] < Bs[b]:
            a+=1
        else:
            pointA += 1
            a+=1
            b+=1

    a,b = 0,0
    while b < M:
        if Bs[b] < As[a]:
            b+=1
        else:
            a+=1
            b+=1
    pointAtrue = M - a


    str = "Case #{0}: {1} {2}\n".format(n, pointA, pointAtrue)
    return str
    # print pointA, pointAtrue






    pass

if __name__ == "__main__":
    with open('4input.txt', 'r') as infile, open('4output.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(map(float, line.split()))

        N = int(data.pop(0)[0])
        for n in xrange(N):
            M = int(data.pop(0)[0])
            As = data.pop(0)
            Bs = data.pop(0)
            # solve(n+1, M, As, Bs)
            outfile.write(solve(n+1, M, As, Bs))





            # outfile.write(solve(vectors) + '\n')