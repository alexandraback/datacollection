
buckets = []
def shift(num,min,max):
    s = str(num)
    length = len(s)
    count = 0
    for i in range(1,length):
        if s[length-i] == '0' or int(s[length-i]) < int(s[0]):
            continue
        tmp = int(s[length-i:] + s[0:length-i])
        if tmp >= min and tmp <= max and buckets[tmp] == 0:
            count += 1 
            buckets[tmp] = 1
    return count * (count+1) / 2

def main():
    
    f = open('./test3', 'r')
    w = open('./out3.txt','w')
    count = int(f.readline())
    for i in range(0,count):
        global buckets
        buckets = [0] * 2000000
        l = f.readline().split(' ')
        min = int(l[0])
        max = int(l[1])
        #for j in range(min,max+1):
        ans = 0
        for j in range(min,max+1):
            buckets[j] = 1
            ans +=shift(j,min,max)
        
        print "Case #%d: %d" %(i+1,ans)
        w.write("Case #%d: %d\n" %(i+1,ans))
    
main()