"""
    Used to solve google code jam 2013 Round 1C - Problem B
    Owner: Jamie Xu - jamie.xue@gmail.com
"""
import math
def better():
    """
        File Handle
    """
#    in_f = open('A-small-attempt0.in', 'r')
#    in_f = open('A-large.in', 'r')
    in_f = open('B-small-attempt0.in', 'r')
    out_f = open('output.txt', 'w')
    num_of_case = int(in_f.readline().rstrip('\n'))
    for i in range(1, num_of_case+1):
        solve_case(in_f, out_f, i)

        
def solve_case(in_f, out_f, case_index):
    """
        Fetch case info
    """
#    print "start handling case #{}".format(case_index)
    case_info = in_f.readline().rstrip('\n').split(" ")
    x, y = map(int, case_info)
    print("x={}, y={}").format(x, y)
    y_str = get_Y_steps(y)
    x_str = get_X_steps(x)
    str = x_str + y_str
    print str
#    line = in_f.readline().rstrip('\n')
#    num_list = line.split(" ")
#    for x in xrange(0, N):
#        num_list[x] = int(num_list[x])
#    num_list.sort()
#
#    min_steps = get_min_steps(0, init_size, num_list)
    out_f.write("Case #{}: {}\n".format(case_index, str))

def get_Y_steps(y):
    if y == 0:
        s = ""
    elif y < 0:
        s = "NS" * (y*-1)
    else:
        s = "SN" * y
    return s
    
def get_X_steps(y):
    if y == 0:
        s = ""
    elif y < 0:
        s = "EW" * (y*-1)
    else:
        s = "WE" * y
    return s

if __name__ == '__main__':    
    better()

