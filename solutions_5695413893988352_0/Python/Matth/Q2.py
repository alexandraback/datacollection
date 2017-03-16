fin = open("in.in")
fout = open("out.out","w")
data = fin.read().split("\n")
T = int(data.pop(0))
fin.close()

def cal(a, b):
    global m, gooda, goodb
    #print a, b
    if a.find('?') == -1 and b.find('?') == -1:
        if m > abs(int(a)-int(b)):
            m = abs(int(a)-int(b))
            gooda = a
            goodb = b
        return
    for i in range(10):
        if a.find('?') != -1: 
            cal(a.replace('?',str(i),1),b)
        else: 
            cal(a,b.replace('?',str(i),1))
        
for i in range(1, T+1):
    a, b = data[i-1].split(' ')
    gooda = goodb = ''
    m = 9999
    cal(a,b)
    print >>fout, "Case #%d: %s %s" % (i, gooda, goodb)
fout.close()