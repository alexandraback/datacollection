import sys

def gcd(a, b):
    if a < b:
        return gcd(b, a)
    if a%b == 0:
        return b
    return gcd(b, a%b)

def is_possible(p, q):
    g = gcd(p, q)
    qq = q / g
    for i in range(40):
        if qq == 1:
            return True
        elif qq % 2 != 0:
            return False
        else:
            qq /= 2
    if qq == 1:
        return True
    return False

def get_pow(n):
    ans = 1
    for i in range(n):
        ans *= 2
    return ans

def get_min_pow(x):
    ans = 1
    for i in range(41):
        if ans >= x:
            return i
        ans *= 2
    return -1

if __name__ == "__main__":

    if(len(sys.argv)) != 2:
        exit(1)
    else:
        input_file = open(sys.argv[1])

    l = input_file.readline()
    line = l.rstrip()
    T = (int)(line)

    

    for i in range(1, T+1):
        #print "Case #" + str(i) + ": "
        #
        l = input_file.readline()
        line = l.rstrip()
        a = line.split("/")
        p = (int)(a[0])
        q = (int)(a[1])
        
        if (not is_possible(p, q)):
            print "Case #" + str(i) + ": " + "impossible"
        
        else:
            print "Case #" + str(i) + ": " + str(get_min_pow((float)(q)/p))



    input_file.close()
