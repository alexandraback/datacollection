import math

def float_to_string(number):
    return ("%101.0f" % number).strip()

def get_int_str(number):
    n_str = float_to_string(number)
    return n_str.split(".")[0]

def get_first_digits(number, how_many):
    n_str = get_int_str(number)
    return n_str[0:how_many]

def half_size(value):
    return int(math.ceil(float(value)/2)) 

def get_end_for_size(size):
    return float("".join(['9']*size))
def get_first_for_size(size):
    return float("".join(['1'] + ['0']*(size-1)))

def reverse_string(string):
    return string[::-1]

def is_palyndrome(number):
    n_str = get_int_str(number)
    size = len(n_str)
    if size % 2 == 0:
        first_half = n_str[0:size/2]
        second_half = n_str[size/2:len(n_str)]        
        
    else:
        first_half = n_str[0:size/2]
        second_half = n_str[(size/2 + 1):len(n_str)]
    return first_half == reverse_string(second_half)

def generate_palyndrome(half, size):
    if size==1:
        return half
    else:
        if size % 2 == 0:
            half_str = get_int_str(half)
            return half_str + reverse_string(half_str)
        else:
            half_str = get_int_str(half)
            prefix = half_str[0:-1]
            middle = half_str[-1]
            suffix = reverse_string(prefix)
            return prefix+middle+suffix
    
def generate_palindromes(start,end):
    count  = 0
    start_size = len(get_int_str(start))
    end_size = len(get_int_str(end))
    end_half = get_first_digits(end, half_size(end_size))
        
    current_size = start_size
    current_half  = float(get_first_digits(start, half_size(current_size)))
    current_half_size_end = get_end_for_size(half_size(current_size))
    
    while True:
        pal = float(generate_palyndrome(current_half, current_size))
        if pal > end:
            break
        
        if pal >= start:
            pal_str = float_to_string(pal)
            p2 = math.pow(pal,2)            
            if is_palyndrome(p2):
                #print float_to_string(pal), float_to_string(p2), is_palyndrome(p2)
                count = count + 1
            elif len(pal_str) == pal_str.count('0') + pal_str.count('1'):
                #print pal_str
                count  =  count
            
        current_half =  current_half + 1.0
        if current_half > float(current_half_size_end):
                current_size = current_size + 1
                current_half_size_end = get_end_for_size(half_size(current_size))
                current_half = get_first_for_size(half_size(current_size))                
            
    return count


def get_numbs(start,end):
    start = math.ceil(math.sqrt(start))
    end = math.floor(math.sqrt(end))
    pals = generate_palindromes(start, end)
    return pals



file = open("C-small-attempt0.in")
lines = file.readlines()
lines = lines[1:]

out = open("results.out", "w")
for i in range(len(lines)):
    splits = lines[i].split(" ")
    start = float(splits[0])
    end = float(splits[1])
    print >> out, "Case #"+str(i+1)+":",get_numbs(start,end)



