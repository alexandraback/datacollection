#!/usr/bin/python2

if __name__ == "__main__":

    f = open('C-small-attempt0.in')
    tc = int(f.readline().strip())

    for t in range(tc):
        print "Case #%d:" % (t + 1)

        n, rest = f.readline().split(" ", 1)
        n = int(n)
        numbers = rest.split()
        numbers = [int(i) for i in numbers]

        sums = {}
        subset = []
        use = []
        for i in range(1 << 20):
            use = []
            for j in range(20):
                if i & (1 << j):
                    use.append(numbers[j])
            temp = sum(use)
            if sums.get(temp):
                another = sums[temp]
                for j in range(20):
                    if another & (1 << j):
                        subset.append(numbers[j])
                break
            else:
                sums[temp] = i
        if subset:
            for i in use: print i,
            print
            for i in subset: print i,
            print
        else:
            print "Impossible"

