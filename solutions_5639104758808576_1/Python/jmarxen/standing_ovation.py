# Standing ovation

# read input
num_test_cases = int(raw_input())

test_cases = []
rnt = range(num_test_cases)
for x in rnt:
    test_cases.append(raw_input().split(" "))

def friends_needed(test_case):
    max_shy = int(test_case[0])
    audience = [int(x) for x in list(test_case[1])]
    total_sum = 0
    num_friends = 0
    cur_shy = 0
    
    while cur_shy <= max_shy:
        if total_sum < cur_shy:
            num_friends += 1
            total_sum += 1
        
        total_sum += audience[cur_shy]
        
        cur_shy+=1
        
    return num_friends

output = ["Case #"+str(x+1)+": "+str(friends_needed(test_cases[x])) for x in rnt]

for x in output:
    print x