def index_by_route(route, current_index, base_len):
    if (len(route)==0):
        return current_index+1
    else:
        local_index = route[0]-1
        current_index = current_index*base_len + local_index
        return index_by_route(route[1:], current_index, base_len)

def divide_into_parts(global_route, max_length):
    result = []
    for i in xrange(0,len(global_route),max_length):
        result.append(global_route[i:i+max_length])
    diff = max_length-len(result[-1])
    if diff > 0:
        result[-1] = [1]*diff + result[-1]
    return result
    
        
num_test = int(raw_input())
for test_case in xrange(1,num_test+1):
    base_len, complexity, students = [int(s) for s in raw_input().split(" ")]
    if base_len > students*complexity:
        print "Case #{}: IMPOSSIBLE".format(test_case)
        continue
    blocks_to_check = range(1, base_len+1)
    indices = []
    routes = divide_into_parts(blocks_to_check, complexity)
    for route in routes:
        indices.append(index_by_route(route, 0, base_len))
    line = ""
    for index in indices:
        line += str(index) + " "
    print "Case #{}: {}".format(test_case, line)