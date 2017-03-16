import sys

#ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" 

# Z . W H . . X . G .

# ONE
# SEVEN

def decrease(tmp, letter, word, symbol):
    res = ''
    while tmp.get(letter, 0):
        for w in word:
            tmp[w] = tmp[w] - 1
        res += symbol
    return res

lines = sys.stdin.readlines()
cases = int(lines[0])
line = 1
for case in xrange(cases):
    tmp = {}
    for letter in lines[line].strip():
        tmp[letter] = tmp.get(letter, 0) + 1
    word = ''
    for l, w, s in [('Z', 'ZERO', '0'), ('W', 'TWO', '2'), ('X', 'SIX', '6'), ('G', 'EIGTH', '8'), ('H', 'THREE', '3')]:
        word += decrease(tmp, l, w, s)
    for l, w, s in [('R', 'FOUR', '4'), ('F', 'FIVE', '5'), ('I', 'NINE', '9'), ('O', 'ONE', '1'), ('S', 'SEVEN', '7')]:
        word += decrease(tmp, l, w, s)
    
    result = ''.join(sorted(word))
    line += 1
    print "Case #%i: %s" % (case + 1, result)
