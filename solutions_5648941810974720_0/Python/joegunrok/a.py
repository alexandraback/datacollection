from sys import stdin as IN
for _ in range(int(IN.readline())):
    print "Case #%s:" % (_+1),
    answer = ""
    WORDS = ("ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE")
    KEYS = ((0, "Z",), (2, "W"), (4, "U"), (5, "V"), (6, "X"), (8, "G"), (1, "O"), (9, "N"), (7, "S"), (3, "H"),)
    answer = []
    S = IN.readline().strip()
    for num, key in KEYS:
        c = S.count(key)
        for _ in range(c):
            found = True
            for _ in WORDS[num]:
                if _ not in S:
                    found = False
            if found:
                answer.append(num)
                for _ in WORDS[num]:
                    S = S.replace(_, "", 1)
    print "".join(map(str, sorted(answer)))
