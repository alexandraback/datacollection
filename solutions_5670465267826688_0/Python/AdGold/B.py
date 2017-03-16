mul = {'1': {'1':'1','i':'i' ,'j':'j' ,'k':'k' },
       'i': {'1':'i','i':'-1','j':'k' ,'k':'-j'},
       'j': {'1':'j','i':'-k','j':'-1','k':'i' },
       'k': {'1':'k','i':'j' ,'j':'-i','k':'-1'} }

class Quarternion:
    def __init__(self, val):
        self.val = val.strip('-')
        self.sign = -1 if '-' in val else 1
    def __mul__(self, other):
        new = Quarternion(mul[self.val][other.val])
        new.sign *= self.sign*other.sign
        return new
    def __repr__(self):
        return '-'*(self.sign == -1) + self.val

f = list(open('C-small-attempt0.in'))
T = int(f.pop(0))
for t in range(1,T+1):
    n,x = f.pop(0).split()
    whole = list(map(Quarternion, f.pop(0).strip()*int(x)))
    try:
        for look in 'ijk':
            cur = Quarternion('1')
            while cur.val != look or cur.sign != 1:
                cur *= whole.pop(0)
                #print(repr(cur))
            #print('Found: '+look)
        cur = Quarternion('1')
        for w in whole:
            cur *= w
        if cur.val == '1' and cur.sign == 1: res = 'YES'
        else: res = 'NO'
    except IndexError:
        res = 'NO'
    print('Case #%d: %s' % (t, res))
