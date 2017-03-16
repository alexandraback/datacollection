
def solve(t):
    items = [int(x) for x in raw_input().strip().split()]
    n = items[0]
    s = items[1:]
    snum = sorted([(s[i],i) for i in range(n)])
    
    ss = [x[0] for x in snum]
    smap = [x[1] for x in snum]

    total = sum(ss)
    used = 0
    k = 0
    for i in range(n-1):
        need = (ss[i+1] - ss[i]) * (i+1)
        if need > total - used:
            break
        used += need
        k += 1

    min_score = ss[k] + float(total - used)/(k+1)

    sol = []
    for x in s:
        if x >= min_score:
            sol.append(0)
        else:
            sol.append(float((min_score - x)*100)/total)

    print ("Case #%d: " % t) + ' '.join([str(x) for x in sol])



def main():
    t = int(raw_input())
    for i in range(t):
        solve(i+1)

if __name__=='__main__':
    main()
