import fractions
import math
if __name__ == '__main__':
    f1 = open("input", "r")
    f2 = open("output", "w")
    T = int(f1.readline())
    for i in range(1,T+1):
        f2.write("Case #"+str(i)+": ")
        l = f1.readline().split("/")
        r = fractions.Fraction(int(l[0]),int(l[1]))
        if(math.log(r.denominator,2) != int(math.log(r.denominator,2))):
            f2.write("impossible\n")
            continue
        g = 1
        x = r*2
        while x < 1 and g < 41:
            x = x*2
            g = g + 1
        f2.write(str(g)+"\n")
        
        
            
    
