##reg = {}
##sup = {}
##
##for x in range(31):
##    reg[x] = set()
##    sup[x] = set()
##
##for i in range(11):
##    for j in range(max(0, i-2), min(10, i+2)+1):
##        for k in range(max(0, i-2), min(10, i+2)+1):
##            m = max(i, j, k)
##            s = i + j + k
##            if abs(j - k) > 2:
##                continue
##            elif abs(j-k) == 2 or abs(i-j) == 2 or abs(i-k)==2:
##                sup[s].add(m)
##            else:
##                reg[s].add(m)
##
##for x in range(31):
##    reg[x] = max(reg[x])
##    if len(sup[x]) != 0:
##        sup[x] = max(sup[x])
##    else:
##        del sup[x]
    
sup = {2: 2, 3: 2, 4: 2, 5: 3, 6: 3, 7: 3, 8: 4,
       9: 4, 10: 4, 11: 5, 12: 5, 13: 5, 14: 6,
       15: 6, 16: 6, 17: 7, 18: 7, 19: 7, 20: 8,
       21: 8, 22: 8, 23: 9, 24: 9, 25: 9, 26: 10,
       27: 10, 28: 10}
reg = {0: 0, 1: 1, 2: 1, 3: 1, 4: 2, 5: 2, 6: 2,
       7: 3, 8: 3, 9: 3, 10: 4, 11: 4, 12: 4,
       13: 5, 14: 5, 15: 5, 16: 6, 17: 6, 18: 6,
       19: 7, 20: 7, 21: 7, 22: 8, 23: 8, 24: 8,
       25: 9, 26: 9, 27: 9, 28: 10, 29: 10, 30: 10}
rev_sup = {0: [], 1: [],
           2: [2, 3], 3: [5, 6], 4: [8, 9],
           5: [11, 12], 6: [14, 15], 7: [17, 18],
           8: [20, 21], 9: [23, 24], 10: [26, 27]}

T = input()

for c in range(1, T+1):
    r = map(int, raw_input().strip().split(' '))
    N = r[0]
    S = r[1]
    p = r[2]
    scores = r[3:]

    best_reg_scores = map(lambda x: reg[x], scores)
    reg_counts = len(filter(lambda x: x >= p, best_reg_scores))
    sup_counts = len(filter(lambda x: x in rev_sup[p], scores))

    print 'Case #%d:' % c, (reg_counts + min(sup_counts, S))
