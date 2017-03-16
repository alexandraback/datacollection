'''
Created on Apr 27, 2012

@author: Josh
'''
import string


def sim_round (levels, stars):
    #print 'begin sim', levels, stars
    #for i in reversed(range(0, len(levels))):
    #    if levels[i][2] == 2:
    #        del levels[i]
        
    attempts = 0
    add_stars = 0
    
    for i in range(0, len(levels)):
        level = levels[i]
        if level[2] < 2:
            #print 'here', level[2], level[1], stars
            if level[1] <= stars:
                attempts += 1
                add_stars += 2 - level[2]
                level[2] = 2
                
    
    if attempts > 0:
        return attempts, add_stars
   
    for i in range(0, len(levels)):
        level = levels[i]
        if level[2] < 1:
            if level[0] <= stars:
                level[2] = 1
                return 1, 1
    return 0,0
    
def sort_key(x):
    return x[0] - x[1]
   
def solve(input_file):
    num_levels = int(input_file.readline())
    
    levels = []
    for i in range(0, num_levels):
        line = string.split(input_file.readline())
        #print 'line', line
        line = map(int, line)
        levels.append([line[0], line[1], 0])
        
    levels.sort(key=sort_key)
    print 'levels', levels
    
    stars = 0
    attempts = 0
    add_attempts = -1
    while add_attempts != 0:
        print 'stars', stars
        print 'attempts', attempts
        add_attempts, add_stars = sim_round(levels, stars)
        stars += add_stars
        attempts += add_attempts
        #print 'round', add_attempts, add_stars
        #print 'levels', levels
    print 'stars', stars
    if stars < num_levels * 2:
        answer = 'Too Bad'
    else:
        answer = attempts
    
    print 'answer', answer
    return answer


def print_answer(num, answer, out):
    out.write ('Case #%s: %s\n' % (num, answer))
    

if __name__ == '__main__':
    FILE = 'two'

    input_file = open ('%s.in' % (FILE,), 'r')
    output_file = open('%s.out' % (FILE,), 'w')
    
    num_cases = int(input_file.readline())
    
    for i in range(1, num_cases+1):
        print '\n', i, '============================================'
        answer = solve(input_file)
        print_answer(i, answer, output_file)
    
    output_file.close()