
# coding: utf-8

# In[2]:

cin = None
cout = None


# In[3]:

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


# In[7]:

def solve():
    A, B, K = read_int()
    write(sum([sum([(x&y)<K for y in range(B)]) for x in range(A)]))


# In[5]:

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


# In[9]:

id = 'B'
work(id)
with open('%s.out' % id) as f:
    print f.read()


# In[37]:



