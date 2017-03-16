def solve(i, C, F, X):
    current = 2.0
    time = 0
    if C >= X:
        time = X / 2.0
    else:
        while True:
            home_time = C / current
            print (X - C) / current, X / (current + F)
            if (X - C) / current <= X / (current + F):
                time += X / current
                break
            time += home_time
            current += F


    str = "Case #{0}: {1}\n".format(i, round(time, 8))
    return str



if __name__ == "__main__":
    with open('2input.txt', 'r') as infile, open('2output.txt', 'w') as outfile:
        data = []
        for line in infile:
            data.append(map(float, line.split()))

        N = int(data.pop(0)[0])
        for n in xrange(N):
            C, F, X = data.pop(0)
            # if C - X > 0:
            #     print "C is bigger", n+1, X / 2.0
            #     print solve(n+1, C, F, X)
            outfile.write(solve(n+1,C, F, X))
