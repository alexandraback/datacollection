
buckets = {}
def shift(num):
    global buckets
    s = str(num)
    length = len(s)
    for i in range(1,length):
        base = 10 ** i
        if s[length-i] == '0' or int(s[length-i]) < int(s[0]):
            continue
        tmp = num/base + (num%base) * (10 ** (length - i))
        if tmp > num:
            buckets[num].append(tmp)
    #return count * (count+1) / 2

def main():
    
    f = open('./test3', 'r')
    w = open('./out3.txt','w')
    count = int(f.readline())
    
    global buckets
    for i in range(1,2000001):
        buckets[i] = []
        shift(i)
    
    for i in range(0,count):
        l = f.readline().split(' ')
        min = int(l[0])
        max = int(l[1])
        #for j in range(min,max+1):
        ans = 0
        visited = [0]*(max+1)
        for j in range(min,max+1):
            counter = 0
            for m in buckets[j]:
                if m > min and m <= max and visited[m] == 0:
                    counter += 1
                    visited[m] = 1
            ans += counter * (counter+1) / 2
            """if buckets[j] == 1:
                continue
            buckets[j] = 1
            ans +=shift(j,min,max)"""
        
        print "Case #%d: %d" %(i+1,ans)
        w.write("Case #%d: %d\n" %(i+1,ans))
    
main()