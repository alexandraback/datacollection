from collections import defaultdict

numbers = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

def CalSingle(nac, ch, idx):
    n = nac[ch]
    for c in numbers[idx]:
        nac[c] -= n
    return n

for case in range(1, int(raw_input())+1):
    print "Case #%d:"%case,
    s = raw_input()
    ac = defaultdict(int)
    for c in s:
        ac[c] += 1

    ans = [0]*10
    # get 0
    ans[0] = CalSingle(ac, "Z", 0)
    ans[8] = CalSingle(ac, "G", 8)
    ans[2] = CalSingle(ac, "W", 2)
    ans[6] = CalSingle(ac, "X", 6)
    ans[4] = CalSingle(ac, "U", 4)
    ans[5] = CalSingle(ac, "F", 5)
    ans[3] = CalSingle(ac, "R", 3)
    ans[7] = CalSingle(ac, "S", 7)
    ans[9] = CalSingle(ac, "I", 9)
    ans[1] = CalSingle(ac, "N", 1)
    aa = ""
    for k, v in enumerate(ans):
        aa += (str(k)*v)
    print aa.strip()

