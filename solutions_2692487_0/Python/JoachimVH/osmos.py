'''
Created on 4-mei-2013

@author: Joachim
'''

def handle_case(line1, line2):
    size = int(line1.split()[0])
    others = sorted(int(x) for x in line2.split())
    return min(len(others), single_step(size, others, len(others)))    
    
def single_step(size, others, max_steps):
    if max_steps <= 0:
        return 9999999
    while len(others) > 0 and others[0] < size:
        size += others[0]
        others = others[1:]
    
    # TODO: <= 1
    if len(others) <= 1:
        return len(others)
    
    # try remove
    new_others = others[:-1]
    remove = 1 + single_step(size, new_others, max_steps-1)
    
    # try add
    if size <= 1:
        return remove
    new_others = [size-1] + others
    add = 1 + single_step(size, new_others, max_steps-1)
    return min(remove, add)
    


f = open(r"c:/Temp/input.txt", "r")
cases = int(f.readline())
out = open("c:/Temp/output.txt", "w")
for i in xrange(1, cases+1):
    out.write("Case #%d: %d\n" % (i, handle_case(f.readline().strip(), f.readline().strip())))
f.close()
out.close()