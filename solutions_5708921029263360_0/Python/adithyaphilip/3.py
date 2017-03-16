def op(case, l):
    print("Case #%d: %d" % (case+1, len(l)))
    for row in l:
        print(row[0],row[1]%100,row[2]%200)


def isSafe(k, comb, ch):
#    print(comb[ch], k)
    if comb[ch] >= k:
        return False
    else:
        return True

def main():
    for _ in range(int(input())):
        cl = list(map(int, input().split()))
        kn = cl[-1]
        cl = cl[:-1]
        
        comb = {}
        for i in range(3):
            for j in range(i+1, 3):
                for p1 in range(1, cl[i]+1):
                    for p2 in range(1, cl[j]+1):
                        comb[(i*100 + p1, j*100 + p2)] = 0
        poss = []
        for i in range(1, cl[0]+1):
            for j in range(1, cl[1]+1):
                for k in range(1, cl[2] + 1):
                    poss.append((i, 100 + j, 200 + k))

        safe = []
        for row in poss:
            if isSafe(kn, comb, (row[0], row[1])) and isSafe(kn, comb, (row[0], row[2])) and isSafe(kn, comb, (row[1], row[2])):
                comb[(row[0], row[1])]+=1
                comb[(row[0], row[2])]+=1
                comb[(row[1], row[2])]+=1
#                print(comb)
                safe.append(row)
                
        op(_, safe)
                
main()
