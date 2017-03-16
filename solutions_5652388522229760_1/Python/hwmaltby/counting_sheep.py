#Henry Maltby
#Code Jam 2016

f = open('A-large.in')
g = open('A-large.out', 'w')

N = int(f.readline())
data = [int(x) for x in f.read().split('\n')]

def count_sheep(n):
    """
    Takes a number and returns the last value Bleatrix would say.
    Does so directly: iterates over each number said and each digit in number.
    """
    digits = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
    k = 0
    if n == 0:
        return 'INSOMNIA'
    while digits != set():
        k += 1
        s = str(k * n)
        for i in range(len(s)):
            if int(s[i]) in digits:
                digits.remove(int(s[i]))
    return s

for i in range(len(data)):
    g.write("Case #" + str(i + 1) + ": " + count_sheep(data[i]) + "\n")
