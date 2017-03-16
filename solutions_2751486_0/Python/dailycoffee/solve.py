V = 'aeiou'

def solve(name, n):
    l = len(name)
    total = 0
    for i in range(l):
        for j in range(i + n, l + 1):
            sub = name[i:j]
            #print sub
            max_count = -1
            count = 0
            for c in sub:
                if not c in V:
                    count += 1
                    max_count = max(max_count, count)
                else:
                    count = 0
            max_count = max(max_count, count)
            if max_count >= n:
                #print '- yes', max_count
                total += 1
    return total

def line(f):
    return f.readline().split()

def main(f):
    (T,) = line(f)
    for i in range(int(T)):
        name, n = line(f)
        print('Case #{}: {}'.format(i + 1, solve(name, int(n))))

if __name__ == '__main__':
    import sys
    main(sys.stdin)
    #with open('sample.in') as f:
        #main(f)
