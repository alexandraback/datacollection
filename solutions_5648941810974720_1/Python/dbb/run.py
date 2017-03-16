import sys

WORDS = [
  ("ZERO", 0),
  ("TWO", 2),
  ("SIX", 6),
  ("FOUR", 4),
  ("EIGHT", 8),
  ("THREE", 3),
  ("ONE", 1),
  ("FIVE", 5),
  ("SEVEN", 7),
  ("NINE", 9),
]

sys.stdin.readline()
casen = 0
while 1:
    ln = sys.stdin.readline()
    if not ln:
        break
    casen += 1
    ln = ln.strip()
    in_chars = {}
    out = []
    for c in ln:
        if c not in in_chars:
            in_chars[c] = 0
        in_chars[c] += 1
    for word, i in WORDS:
        w_chars = {}
        for c in word:
            if c not in w_chars:
                w_chars[c] = 0
            w_chars[c] += 1
        # print 'w_chars:', w_chars
        while 1:
            # print 'in_chars:', in_chars
            found = True
            for c, count in w_chars.items():
                if c not in in_chars:
                    found = False
                    break
                if in_chars[c] < w_chars[c]:
                    found = False
                    break
            if not found:
                break
            out.append(i)
            for c, count in w_chars.items():
                in_chars[c] -= count
    out = sorted(out)
    s = ''
    for i in out:
        s += str(i)
    print 'Case #%d: %s' % (casen, s)
