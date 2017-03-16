maxi = 0
count = 0
count1 = 0

def rec (word, target, s, keyboard):
    global maxi
    global count
    global count1

    if len(word) == s:
        temp = 0
        for i in range(0, s+1):
             if word[i:i+len(target)] == target:
                  temp += 1
        count += temp
        maxi = max(maxi, temp)
        count1 += 1
    else:
        for i in keyboard:
            rec(word + i, target, s, keyboard)


t = input()
for tests in range(1, t + 1):
        k, l, s = map(int, raw_input().split())
        keyboard = raw_input()
        target = raw_input()
        maxi = 0
        count = 0
        count1 = 0
        rec("", target, s, keyboard)
        print "Case #" + str(tests) + ": " + str(round(maxi - count * 1.0 / count1, 7))
