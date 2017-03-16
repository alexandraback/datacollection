from collections import Counter

T = input()
for i in range(T):
    S = raw_input()

    cnt = Counter()
    for l in S:
        cnt[l] += 1

    # Count the unique letter for each number
    # (some are unique only after counting other numbers)
    search = [('ZERO','Z',0),('TWO','W',2),('SIX','X',6),('EIGHT','G',8),
              ('THREE','H',3),('FOUR','R',4),('ONE','O',1),('FIVE','F',5),
              ('SEVEN','V',7),('NINE','I',9)]
    digits = []
    for n,l,d in search:
        count = cnt[l]
        digits += [d]*count
        for x in n:
            cnt[x] -= count

    sol = ''.join(map(str,sorted(digits)))
    print 'Case #'+str(i+1)+": " + sol
