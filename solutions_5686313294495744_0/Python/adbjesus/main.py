from itertools import combinations

def solve():
    C = int(input())
    W = []

    for c in range(C):
        W.append([s for s in input().split()])
   

    # OPPOSITE LOGIC
    for c in range(1,C):
        # if c are true
        for z in combinations(W,c):
            tmp = W[::]
            fw = []
            sw = []
            for e in z:
                tmp.remove(e)
                fw.append(e[0])
                sw.append(e[1])

            finish = True
            for e in tmp:
                if not (e[0] in fw and e[1] in sw):
                    finish = False
                    break

            if finish:
                return C-c


    """
    count = 0
    for w in W:
        if fw.count(w[0]) > 1 and sw.count(w[1]) > 1:
            count += 1
    
    # Check extreme case
    W2 = [' '.join(w) for w in W]
    checked = []
    for i in range(len(W)):
        if W2[i] in checked:
            continue
        if W2.count(W2[i]) > 1:
            checked.append(W2[i])
            # Check first word
            c1 = False
            c2 = False
            for j in range(len(W)):
                if W2[i] != W2[j] and W[i][0] == W[j][0]:
                    c1 = True
                    break

            for j in range(len(W)):
                if W2[i] != W2[j] and W[i][1] == W[j][1]:
                    c2 = True
                    break

            if not (c1 and c2):
                count -= 1
    """

    return 0

T = int(input())
for t in range(1,T+1):
    print("Case #%d: %d" % (t,solve()))
