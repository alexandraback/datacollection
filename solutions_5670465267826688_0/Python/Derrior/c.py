import sys

class Quater:
    def __init__(self, c = chr(ord('i') - 1)):
                
        self.sign = 1
        self.n = ord(c) - ord('i') + 1
        
    def __imul__(self, other):
        if self.n == 0 or other.n == 0:
            self.n += other.n
            return self
        elif self.n == other.n:
            self.n = 0  
            self.sign *= -other.sign
            return self
        else:
            if self.n == 1:
                if other.n == 2:
                    self.n = 3
                    self.sign *= other.sign
                    return self
                self.n = 2
                self.sign *= -(other.sign)
                return self
            if self.n == 2:
                if other.n == 1:
                    self.n = 3
                    self.sign *= -(other.sign)
                    return self
                self.n = 1
                self.sign *= other.sign
                return self
            else:
                if other.n == 1:
                    self.n = 2
                    self.sign *= other.sign
                    return self
                else:
                    self.n = 1
                    self.sign *= -(other.sign)
                    return self
                
    def __str__(self):
        ret = ''
        if self.sign < 0:
            ret += '-'
        if self.n == 0:
            ret += '1'
        else:
            ret += chr(ord('i') + self.n - 1)
        return ret
    
    def __eq__(self, other):
        return self.n == other.n and self.sign == other.sign
    
    def __ne__(self, other):
        return not(self == other)
    
    def __itruediv__(self, other):
        if self.n == 0 or other.n == 0:
            self.n += other.n
            return self
        elif self.n == other.n:
            self.n = 0
            self.sign *= -other.sign
            return self
        else:
            if self.n == 1:
                if other.n == 2:
                    self.n = 3
                    self.sign *= -other.sign
                    return self
                self.n = 2
                self.sign *= (other.sign)
                return self
            if self.n == 2:
                if other.n == 1:
                    self.n = 3
                    self.sign *= (other.sign)
                    return self
                self.n = 1
                self.sign *= -other.sign
                return self
            else:
                if other.n == 1:
                    self.n = 2
                    self.sign *= -other.sign
                    return self
                else:
                    self.n = 1
                    self.sign *= (other.sign)
                    return self        
def solve(index):
    l, x = map(int, fin.readline().rstrip().split())
    string = fin.readline().rstrip() * x
    #print('\n'.join(map(str, list(enumerate(list(string))))))
    l *= x
    I = Quater('i')
    J = Quater('j')
    K = Quater('k')
    a = Quater()
    left, right = 0, l - 1
    while a != I and left < l - 1:
        a *= Quater(string[left])
        left += 1
    if a != I:
        #print(1)
        print("Case #%d: NO"%(index + 1), file=fout)
        return
    a = Quater()
    while a != K and right > left:
        a /= Quater(string[right])
        right -= 1
    right += 1
    if a != K or right == left:
        #print(2)
        print("Case #%d: NO"%(index + 1), file=fout)
        return        
    a = Quater()
    #print(left, right)
    while left != right:
        a *= Quater(string[left])
        left += 1
        #print(a)
    if a == J:
        #print(3)
        print("Case #%d: YES"%(index + 1), file=fout)
        return
    else:
        #print(4)
        print("Case #%d: NO"%(index + 1), file=fout)
        return                
    
fin = open("../Downloads/C-small-attempt3.in")
fout = open('c.out', 'w')

t = int(fin.readline().rstrip())
for i in range(t):
    solve(i)
fout.close()
Q = [Quater('i'), Quater('j'), Quater('k')]
a = Quater()
#print()
#for i in range(4):
    #a *= Q[1] 
    ##print(a)
    #a *= Q[2] 
    ##print(a)
    #a *= Q[0] 
#print(a)