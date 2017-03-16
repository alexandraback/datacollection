# hire me and you too could put code like this in production
from string import maketrans
m, T = 0xa0a0fd8dffec, input()
print '\n'.join("Case #%d: %s" % (t, "RICHARD" if (1 << (63 - int(raw_input().translate(maketrans('1234', '0123'), ' '), 4))) & m else "GABRIEL") for t in range(1, T + 1))
