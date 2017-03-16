"""
    Used to solve google code jam 2013 Round 1C - Problem A - Osmos
    Owner: Jamie Xu - jamie.xue@gmail.com
"""
def best():
    """
        File Handle
    """
    in_f = open('A-small-attempt0.in', 'r')
    out_f = open('output.txt', 'w')
    num_of_case = int(in_f.readline().rstrip('\n'))
    for i in range(1, num_of_case+1):
        solve_case(in_f, out_f, i)

N = 0
        
def solve_case(in_f, out_f, case_index):
    """
        Fetch case info
    """
#    print "start handling case #{}".format(case_index)
    case_info = in_f.readline().rstrip('\n').split(" ")
    name = case_info[0]
    N = int(case_info[1])
    print("name={}, N={}").format(name, N)
    cleaned_name = clean_name(name)
    n = get_n(cleaned_name, N)
#    line = in_f.readline().rstrip('\n')
#    num_list = line.split(" ")
#    for x in xrange(0, N):
#        num_list[x] = int(num_list[x])
#    num_list.sort()
#
#    min_steps = get_min_steps(0, init_size, num_list)
    out_f.write("Case #{}: {}\n".format(case_index, n))

def get_n(name, N):
    #
    print name
    print N
    length = len(name)
    if length < N:
        return 0
    temp = 0
    for i in xrange(N, length+1):
        if is_valid(name[0:i], N):
            print name[0:i]
            temp = temp + 1
    return temp + get_n(name[1:], N)

def is_valid(str, N):
    parts = str.split("1")
    for part in parts:
        if len(part) >= N:
            return True
    return False
    
def clean_name(name):
    cleaned_name = name.replace("a", "1").replace("e", "1").replace("i", "1").replace("o", "1").replace("u", "1")
    return cleaned_name
    
if __name__ == '__main__':    
    best()

