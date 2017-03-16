import sys

d = {}
def library():
    a = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv"
    b = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up"
    for i in xrange(len(a)):
        d[a[i]] = b[i]
    d['z'] = 'q'
    d['q'] = 'z'

        
def main(i,fin,fout):
    inp = fin.readline().strip()
    for i in inp:
        fout.write(d[i])

if __name__ == '__main__':
    fin = open("a.txt", "r")
    fout = open("aout.txt", "w")
    cases = int(fin.readline())
    library()
    for i in xrange(cases):
        fout.write("Case #%d: " %(i+1))
        main(i,fin,fout)
        fout.write("\n")

    fin.close()
    fout.close()
