
# coding: utf-8

# In[11]:

cin = None
cout = None


# In[12]:

def read():
    global cin
    return cin.readline().strip().split()

def read_int():
    return [int(x) for x in read()]
    
def write(fmt, data=None):
    global cout
    cout.write(data is None and str(fmt) or fmt % data)
    
def write_line():
    write('\n')


# In[39]:

def gcd(a, b):
    while a % b:
        a, b = b, a % b
    return b
import math
def solve():
    P, Q = [int(x) for x in cin.readline().strip().split('/')]
    g = gcd(P, Q)
    p = P / g
    q = Q / g
    r = float(p) / q
    logq = math.log(q, 2)
    if abs(logq - math.floor(logq)) > 0.001:
        write('impossible')
        return
    n = 0
    while r < 1:
        n += 1
        r *= 2
    write(n)


# In[18]:

def work(id):
    global cin, cout
    case_num = 0
    cin = file('%s.in' % id, 'r')
    cout = file('%s.out' % id, 'w')
    case_num = read_int()[0]
    for i in range(case_num):
        write('Case #%d: ', i + 1)
        solve()
        write('\n')
    cin.close()
    cout.close()


# In[41]:

id = 'A'
work(id)
with open('%s.out' % id) as f:
    print f.read()


# In[37]:



