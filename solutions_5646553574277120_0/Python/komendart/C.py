def solve(fin):
    from itertools import combinations
    C, D, V = [int(i) for i in fin.readline().split()]
    values = [int(i) for i in fin.readline().split()]
    varieties = [i for i in range(V + 1) if i != 0 and i not in values]
    for i in range(6):
        for p in combinations(varieties, i):
            p = list(p) + values
            used = [0 for i in range(V + 1)]
            for mask in range(1 << len(p)):
                s = 0
                for j in range(len(p)):
                    if mask & (1 << j):
                        s += p[j]
                if s <= V:
                    used[s] = 1
            if sum(used) == V + 1:
                return i
    

def main():
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(1, t + 1):
            print("Case #{0}: {1}".format(i, solve(fin)), file=fout)
    
    
main()
