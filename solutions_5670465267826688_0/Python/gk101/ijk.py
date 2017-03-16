
class Quaternion_table():

    def __init__(self):
        self.idx = {
            'i': 2, 
            'j': 3, 
            'k': 4,
        }
        
        self.quat = {}
        self.quat[2, 2] = '-1'
        self.quat[2, 3] = 'k'
        self.quat[2, 4] = '-j'
        self.quat[3, 2] = '-k'
        self.quat[3, 3] = '-1'
        self.quat[3, 4] = 'i'
        self.quat[4, 2] = 'j'
        self.quat[4, 3] = '-i'
        self.quat[4, 4] = '-1'
        
    def multiply(self, x, y):
        if x == y and (x == '1' or x == '-1'):
            return '1'
        if x == y:
            return '-1'
        if x == '1':
            return y
        if y == '1':
            return x
        if x == '-1':
            if y[0] == '-':
                return y[1]
            else:
                return '-' + y
        if y == '-1':
            if x[0] == '-':
                return x[1]
            else:
                return '-' + x
        
        is_neg = False
        if x[0] == '-':
            is_neg = not is_neg
            x = x[1]
        if y[0] == '-':
            is_neg = not is_neg
            y = y[1]
        
        result = self.quat[self.idx[x], self.idx[y]]
        
        if is_neg and result[0] == '-':
            return result[1]
        elif is_neg:
            return '-' + result
        elif result[0] == '-':
            return result
        else:
            return result 



def is_ijk(string):
    qt = Quaternion_table()
    left = '1'
    idx = 0
    while idx < len(string) and left != 'i':
        left = qt.multiply(left, string[idx])
        # print "left:", left
        idx += 1
    if idx == len(string):
        return False
    
    right = '1'
    jdx = len(string) - 1
    while jdx > idx and right != 'k':
        right = qt.multiply(string[jdx], right)
        # print "right:", right
        jdx -= 1
    # print idx, jdx, string[idx + 1: jdx + 1]
    if jdx < idx:
        return False
    return calc_middle(string[idx: jdx + 1], qt) == 'j'
    
    
def calc_middle(string, qt):
    curr = '1'
    for c in string:
        curr = qt.multiply(curr, c)
    return curr
 

    
    
print "start..."
file_name = 'C-small-attempt0.in'
out = open('small_ijk0.out', 'w')
with open(file_name) as f:
    T = int(next(f))
    count = 0
    case = 1
    
    for line in f:
        if count % 2 == 0:
            c = [int(i) for i in line.strip().split()]
            copy = c[1]
        else:
            ijk_string = line.replace("\n", "") * copy
            # print ijk_string
            
            if is_ijk(ijk_string):
                a = 'YES'
            else:
                a = 'NO'
                
            out.write("Case #%d: %s\n" % (case, a))
            
            case += 1
            
        count += 1

out.close()
print "done"


# while True:
    # c = raw_input()
    # print is_ijk(c)

    
    
    
    
    
    
    
    
    
    
    
    
    
    