import codecs

def __validateString(train_str):
    if len(train_str) > 2:
        diff = 0
        for s in range(1, len(train_str)):
            if(train_str[s-1] != train_str[s]):
                diff += 1
            if(diff > 1):
                return False
        return True
    else:
        return True

def __allPerms(elements):
    if len(elements) <= 1:
        yield  elements
    else:
        for perm in __allPerms(elements[1:]):
            for i in range(len(elements)):
                yield perm[:i] + elements[0:1] + perm[i:]

def __countValid(trains_candidates):
    valid_perms_cnt = 0
    for t in trains_candidates:
        valid_perm = True
        letters_list = list()
        train_candy = ''.join(t)
        for l in range(len(train_candy)):
            if(train_candy[l] in letters_list):
                if(train_candy[l-1] != train_candy[l]):
                    valid_perm = False
                    break
            else:
                letters_list.append(train_candy[l])
        
        if(valid_perm):
            valid_perms_cnt += 1
    
    return valid_perms_cnt

with codecs.open('B-small-attempt0.in','r','utf-8') as f:
    test_cases = int(f.readline().strip())
    for t in range(test_cases):
        print "Case #%i:" % (t+1),
        f.readline()
        trains_string = f.readline().strip().split(' ')
        trains_not_valid = False
        
        for t in trains_string:
            if(not __validateString(t)):
                print "0"
                trains_not_valid = True
                break
        
        if(not trains_not_valid):
            all_trains = __allPerms(trains_string)
            print __countValid(all_trains)
        
