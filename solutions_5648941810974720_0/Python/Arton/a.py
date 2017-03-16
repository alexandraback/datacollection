alpha = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
s = "ZWUFXVGIRN"
t = [0,2,4,5,6,7,8,9,3,1]
nn = int(input())
for inn in range(nn):
    phone = [0 for inn in range(10)]
    table = {}
    enc = str(input())
    # print(enc)
    enc = enc.strip()
    for c in enc:
        if c in table:
            table[c] += 1
        else:
            table[c] = 1
    # print(table)
    for i, c in enumerate(s):
        # print("###", c)
        if c in table and table[c] > 0:
            num = table[c];
        else:
            continue
        digit = t[i]
        phone[digit] += num
        # print(str(digit)*num, end="")

        # print(table)
        for ch in alpha[digit]:
            table[ch] -= num
    # print(phone)
    ans = []
    for digit, num in enumerate(phone):
        ans.append(str(digit)*num)
    print("Case #%d: %s" % (inn+1, "".join(ans)))

