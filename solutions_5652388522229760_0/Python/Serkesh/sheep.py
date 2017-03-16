
def parse(path):
    files = open(path)
    files.readline()
    content = files.readlines()
    for i in range(len(content)):
        content[i] = int(content[i])
    return content

def count(n):
    if(n==0):
        return "INSOMNIA"
    dec  = [0,0,0,0,0,0,0,0,0,0]
    left = 10
    current = 0
    while (left != 0):
        current += n
        tmp = current
        while (tmp != 0):
            r = tmp % 10
            tmp = tmp // 10
            if(dec[r] == 0):
                dec[r] = 1
                left -= 1
    return current

def test():
    L=["1000\n"]
    lel = 10**5
    for i in range(1000):
        lel += 489+3*i
        L.append(str(lel)+"\n")
    output=(open("tst.txt","w"))
    output.writelines(L)
    
def output():
    data=(parse("A-small-attempt1.in"))
    L = []
    for i in range(len(data)):
        L.append("Case #"+str(i+1)+": "+str(count(data[i]))+"\n")
    output=(open("outputsheep.out","w"))
    output.writelines(L)

output()
