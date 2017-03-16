
V = ['a', 'e', 'i', 'o', 'u']

def consonants(name, n):
    lst =[]
    count = 0
    
    for i in range(len(name)):
        if name[i] in V:
            count = 0
        elif count == n-1:
            lst.append([i-(n-1), i])
        else:
            count = count + 1
    
    return lst

if __name__ == '__main__':
    lines = open("A-large.in").readlines()
    T = int(lines[0])
    ln = 1

    for i in range(1, T+1):
        name, n = lines[i].split()
        n = int(n)
        
        cp = consonants(name, n)

        ans = 0
        for l in cp:
            x, y = l
            ans += (x + 1) * (len(name) - y)

        #print name, n

        for j in range(len(cp)-1):
            k = j + 1
            l1 = cp[j]
            l2 = cp[k]
            x = l1[0]
            y = l2[1]
            #print (((k - j) % 2)*2 - 1) * (x + 1) * (len(name) - y)
            ans -= (((k - j) % 2)*2 - 1) * (x + 1) * (len(name) - y)
                

        print "Case #%d:"%i, ans
                
        
