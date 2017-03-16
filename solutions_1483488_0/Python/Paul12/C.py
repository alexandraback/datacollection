import sys

def main(i,fin,fout):
    inp = map(int, fin.readline().strip().split())
    a = inp[0]
    b = inp[1]
    cnt = 0;
    for n in xrange(a, b):
        test = str(n)
        dic = {}
        for i in xrange(len(test) - 1):
            temp = int(test[i+1:] + test[:i+1])
            if n < temp <= b and temp not in dic:
                cnt += 1
                dic[temp] = 0
    fout.write(str(cnt))

if __name__ == '__main__':
    fin = open("cin.txt", "r")
    fout = open("cout.txt", "w")
    cases = int(fin.readline())
    for i in xrange(cases):
        fout.write("Case #%d: " %(i+1))
        main(i,fin,fout)
        fout.write("\n")

    fin.close()
    fout.close()
