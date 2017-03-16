import struct, string, math

#input read
input_file = open("input1.in", 'rt')
num_cases = int(input_file.readline())

#output write
output_file = open("output1.txt", 'w')

def find_alphabet(train, alpha):
    # no : 0, front: 1, end:2, middle:3, error:4, all:9
    # no alphabet
    if train.find(alpha) < 0 :
        return 0    
    
    # alphabet at front
    if train.find(alpha) == 0:
        while train.find(alpha) == 0:
            train = train[1:]
        if train.find(alpha) < 0 :
            if len(train) == 0:
                return 9
            return 1
        else:
            return 4
    
    #alphabet at the middle or end
    idx = train.find(alpha)
    train = train[idx+1:]
    while train.find(alpha)==0:
        train = train[1:]
    if len(train) == 0:
        return 2
    if train.find(alpha)<0:
        return 3
    else:
        return 4
        


# do the job
def main_job(trains):
    count = 1
    alphabet = string.lowercase
    for alpha in alphabet:
        train_end = []
        train_middle = []
        train_front = []
        train_all = []
        for train in trains:
            result = find_alphabet(train, alpha)
            if result == 4:
                return 0
            elif result == 0:
                continue
            elif result == 1:
                if len(train_front)==0:
                    train_front.append(train)
                else:
                    return 0
            elif result == 2:
                if len(train_end)==0:
                    train_end.append(train)
                else:
                    return 0    
            elif result == 3:
                train_middle.append(train)

            elif result == 9:
                train_all.append(train)
                
                
        if len(train_middle)>0 and (len(train_front) + len(train_end) + len(train_all) > 0):
            return 0
        
        if len(train_front) + len(train_end) + len(train_all) + len(train_middle) < 2:
            continue
        
        front_train = ""
        end_train = ""
        all_train = ""
        if len(train_front) > 0:
            front_train = train_front[0]
            trains.remove(train_front[0])
        if len(train_end) > 0:
            end_train = train_end[0]
            trains.remove(train_end[0])
        if len(train_all) > 0:
            for train in train_all:
                all_train += train     
                trains.remove(train)
            count = count * math.factorial(len(train_all))            
            
        total_train = end_train + all_train + front_train
        trains.append(total_train)
        
    count = (count * math.factorial(len(trains))) % 1000000007
    return count
            
                
                

for i in range(num_cases):
    print i
    line = input_file.readline()
    n = int(line)
    line = input_file.readline()
    trains = line.split()
     
    result = main_job(trains)
    output = "Case #%d: %d\n" %(i+1, result)

    
    output_file.write(output)

input_file.close()
output_file.close()