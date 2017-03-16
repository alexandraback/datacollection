from collections import defaultdict

def letter_counts(s):
    d = defaultdict(int)
    for c in s:
        d[c] += 1
    return d

digits = ["ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"]

digit_letter_counts = {i: letter_counts(digits[i]) for i in xrange(10)}

unique = {
    0: "Z",
    2: "W",
    3: "H",
    4: "O",
    5: "F",
    6: "X",
    7: "V",
    8: "G",
    9: "I",
}

def get_number(s, i):
    if i == 10:
        if sum(s.values()) == 0:
            return []
        return None

    if i == 1 or i == 3:
        x = min([s[c] for c in digits[i]])
        for j in xrange(x+1):
            n = get_number(s, i+1)
            if n is not None:
                n = [i] * j + n
                return n

            for c in digits[i]:
                s[c] -= 1
        for c in digits[i]:
            s[c] += x+1
        return None
    else:
        x = s[unique[i]]
        dc = digit_letter_counts[i]
        neg = False
        for c, j in dc.iteritems():
            s[c] -= j*x
            if s[c] < 0:
                neg = True

        if not neg:
            n = get_number(s, i+1)
            if n is not None:
                n = [i] * x + n
                return n
        for c, j in dc.iteritems():
            s[c] += j*x

        return None

with open("a.in") as f:
    t = int(next(f))
    for case in xrange(t):
        s = next(f).strip()

        print "Case #{}: {}".format(case+1, "".join([str(d) for d in get_number(letter_counts(s), 0)]))
