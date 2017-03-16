import collections

DIGITS = ["ZERO", "ONE", "TWO", "THREE", "FOUR",
          "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]
TESTCASE = int(input())
for test in range(TESTCASE):
    s = input()
    ctr = collections.Counter(s)
    numbers = [0 for i in range(10)]
    for c, word in [['G', 'EIGHT'], ['U', 'FOUR'], ['W', 'TWO'], ['X', 'SIX'], ['Z', 'ZERO'], ['F', 'FIVE'], ['H', 'THREE'], ['O', 'ONE'], ['S', 'SEVEN'], ['I', 'NINE']]:
        numbers[DIGITS.index(word)] = ctr[c]
        for c in word:
            ctr[c] -= numbers[DIGITS.index(word)]
    ans = ''
    for i in range(10):
        ans += str(i) * numbers[i]
    print('Case #' + str(test+1) + ':', ans)
