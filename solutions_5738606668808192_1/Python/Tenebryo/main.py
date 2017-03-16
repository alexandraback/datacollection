def find_small_non_trivial_factor(n, max):
    for i in range(2,max):
        if n % i == 0:
            return i
    return None

def jam_coin_value(n, b):
    r = 0
    m = n
    e = 1
    while m > 0:
        r += (m % 2) * e;
        m  = m >> 1;
        e *= b;
    return r

def main():
    output = "Case #1:\n"
    
    n=32
    j=500
    
    m = (1<<n-1) + 1;
    while j > 0:
        
        fac = []
        failed = False
        
        for jc in range(2,11):
            t = find_small_non_trivial_factor(jam_coin_value(m,jc),8192)
            if t != None:
                fac += [t]
            else:
                failed = True
                break
        
        if not failed:
            output += (bin(m)[2:] + ' ' + ' '.join(map(str,fac)) + '\n')
            j -= 1
        
        m += 2
    
    print(output+'\n')
    
main()