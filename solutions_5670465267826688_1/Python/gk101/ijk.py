
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



def is_ijk(string, copy):
    if len(string) <= 1:
        return False
    
    qt = Quaternion_table()
    
    # search for i from left
    left_set = {}
    left = '1'
    left_set[left] = True
    
    while copy > 0 and left != 'i':
        idx = 0
        while idx < len(string) and left != 'i':
            left = qt.multiply(left, string[idx])
            
            # print "left:", left
            
            idx += 1
        
        if left not in left_set:
            left_set[left] = True
        else:
            return False
        
        copy -= 1
    
    print "left found"
    
    # search for k from right
    right_set = {}
    right = '1'
    right_set[right] = True
    
    while copy > 0 and right != 'k':
        jdx = len(string) - 1
        while jdx >= 0 and right != 'k':
            right = qt.multiply(string[jdx], right)
            
            # print "right:", right
            
            jdx -= 1
            
        if right not in right_set:
            right_set[right] = True
        else:
            return False
        
        copy -= 1
        
    ik_on_same_string = False
    # for when copy is 0
    if right != 'k':
        ik_on_same_string = True
        jdx = len(string) - 1
        while jdx > idx and right != 'k':
            right = qt.multiply(string[jdx], right)
            
            # print "right:", right
            
            jdx -= 1
        # print idx, jdx, string[idx + 1: jdx + 1]
        if jdx < idx:
            return False
        
    print "right found"
    print "searching middle"
    
    
    if ik_on_same_string:
        string1 = string[idx: jdx + 1]
        string2 = ''
    else:
        string1 = string[idx:]
        string2 = string[:jdx + 1]
    
    # print string1, string2, copy
    
    return calc_middle(string1, string2, string, copy, qt) == 'j'
    
    
def calc_middle(string1, string2, original_string, copy, qt):
    # calculate full string multiplication for later
    concat = '1'
    
    if copy > 0:
        full_str_mult = '1'
        
        # compute full string
        for c in original_string:
            full_str_mult = qt.multiply(full_str_mult, c)
        # print "full string multiply:", full_str_mult
        
        # compute all the full strings in the middle
        if full_str_mult == '1':
            concat = '1'
        elif full_str_mult == '-1':
            if copy % 2 == 1:
                concat = '-1'
            else:
                concat = '1'
        else:
            list1 = []
            arr = '1'
            for i in range(4):
                list1.append(arr)
                arr = qt.multiply(arr, full_str_mult)
            concat = list1[copy % 4]
        
        
        
    # compute from right of i
    curr = '1'
    for c in string1:
        curr = qt.multiply(curr, c)
    # print "finished left:", curr
    
    # compute middle full strings if any exist
    curr = qt.multiply(curr, concat)
    # print "finished middle:", curr
    
    # compute string left of k
    for c in string2:
        curr = qt.multiply(curr, c)
    # print "finished right:", curr
    
    return curr
 

    
    
print "start..."
# file_name = 'C-small-attempt0.in'
# out = open('small_ijk_test1.out', 'w')
file_name = 'C-large.in'
out = open('large_ijk.out', 'w')
with open(file_name) as f:
    T = int(next(f))
    count = 0
    case = 1
    
    for line in f:
        if count % 2 == 0:
            c = [int(i) for i in line.strip().split()]
            copy = c[1]
        else:
            ijk_string = line.replace("\n", "")
            # print ijk_string
            if is_ijk(ijk_string, copy):
                a = 'YES'
            else:
                a = 'NO'
            out.write("Case #%d: %s\n" % (case, a))
            print a
            case += 1
        count += 1
out.close()
print "done"


# while True:
    # c = raw_input()
    # print is_ijk(c)

    
    
    
    
    
    
    
    
    
    
    
    
    
    