inFile = open("c.in", "r")
outFile = open("c.out", "w")

def recycled_m(a, b, n):
    n_str = str(n)
    count = 0
    uniq = []
    for i in range(1, len(n_str)):
        m_str = n_str[i:] + n_str[:i]
        m = int(m_str)
        if a <= n < m <= b and len(m_str) == len(n_str) and m not in uniq:
            count += 1
            uniq.append(m)
    return count

caseAmount = int(inFile.readline())
for caseNum in range(1, caseAmount + 1):
    [a, b] = [int(i) for i in inFile.readline().split(" ")]
    result = 0
    for n in range(a, b + 1):
        result += recycled_m(a, b, n)
    outFile.write("Case #{0}: {1}\n".format(caseNum, result))
