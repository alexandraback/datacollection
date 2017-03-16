def solve(fin):
    K, L, S = [int(i) for i in fin.readline().split()]
    letters = fin.readline().strip()
    word = fin.readline().strip()
    result = 0
    maximal = 0
    for i in range(K ** S):
        t = i
        s = ""
        for j in range(S):
            s += letters[t % K]
            t //= K
        number = 0
        for i in range(S - L + 1):
            if s[i: i + L] == word:
                number += 1
        result += number
        maximal = max(maximal, number)
    return maximal - result / K ** S

def main():
    with open("input.txt") as fin, open("output.txt", 'w') as fout:
        t = int(fin.readline())
        for i in range(1, t + 1):
            print("Case #{0}: {1}".format(i, solve(fin)), file=fout)
            
            
            
main()
