def solve(fin):
    n = int(fin.readline())
    hikers = []
    for i in range(n):
        d, h, m = [int(i) for i in fin.readline().split()]
        for i in range(h):
            hikers.append((d, m + i))
    
    if len(hikers) == 1:
        return 0
    
    x1, t1 = hikers.pop()
    x2, t2 = hikers.pop()
    if t1 > t2:
        (x1, t1), (x2, t2) = (x2, t2), (x1, t1)
    if (360 + x2 - x1) * t1 > (360 - x2) * (t2 - t1):
        return 0
    return 1
        

def main():
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(1, t + 1):
            print("Case #{0}: {1}".format(i, solve(fin)), file=fout)
    
main()
