# first figure out zero (z) two (w) four (u) six (x) eight (g) since they all have a unique letter
# then figure out three (h)
# then figure out one (o)
# then figure out seven (s)
# then figure out nine (n)
# then figure out five (f)

def get(freq, number, letter):
    if letter not in freq or freq[letter] == 0:
        return 0

    count = freq[letter] / number.count(letter)

    for i in number:
        freq[i] -= count

    #print freq, number, letter, count
    return count

f = file('a.in', 'r')
T = int(f.readline())
for t in range(1, T + 1):
    line = f.readline().lower().strip()
    freq = {}
    for j in line:
        if j not in freq:
            freq[j] = 1
        else:
            freq[j] += 1

    d = {}
    d[0] = get(freq, 'zero', 'z')
    d[2] = get(freq, 'two', 'w')
    d[4] = get(freq, 'four', 'u')
    d[6] = get(freq, 'six', 'x')
    d[8] = get(freq, 'eight', 'g')
    d[3] = get(freq, 'three', 'h')
    d[1] = get(freq, 'one', 'o')
    d[7] = get(freq, 'seven', 's')
    d[9] = get(freq, 'nine', 'n')
    d[5] = get(freq, 'five', 'f')

    if max(freq.values()) > 0 or min(freq.values()) < 0:
        print freq.values()
        print 'SOMETHING FAILED'

    answer = 'Case #%d: ' % t
    for i in range(10):
        answer += str(i) * d[i]
    print answer
