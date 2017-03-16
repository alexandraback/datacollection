from math import factorial

def solve(trains):
    # Sanity check: middle letters (abc bd)
    letters = {}
    for train in trains:
        for letter in train:
            if letter not in letters.keys():
                letters[letter] = 1
            else:
                letters[letter] += 1
                
    for train in trains:
        for i in xrange(1, len(train) - 1):
            if train[i] != train[i-1] and train[i] != train[i+1] and letters[train[i]] > 1:
                return 0

    # Remove middle letters: abc -> (a, c)
    letter_pairs = []
    for train in trains:
        letter_pairs.append((train[0], train[-1]))
    
    # Combine same letter ends: (a, a) x2
    multiplier = 1
    letter_pairs2 = []
    same_ends = {}
    for letter in letters.keys():
        same_ends[letter] = 0
    
    for lpair in letter_pairs:
        if lpair[0] == lpair[1]:
            same_ends[lpair[0]] += 1
        else:
            letter_pairs2.append(lpair)
    
    for letter, same_end_pairs in same_ends.items():
        multiplier *= factorial(same_end_pairs)
        if same_end_pairs > 0:
            letter_pairs2.append((letter, letter))
      
    letter_pairs = letter_pairs2
  
    # Make a matrix
    pair_matrix = [[0]*26 for _ in xrange(26)]
    first_letters = [[]*26 for _ in xrange(26)]
    last_letters = [[]*26 for _ in xrange(26)]
    for letter_pair in letter_pairs:
        a = ord(letter_pair[0]) - 97
        b = ord(letter_pair[1]) - 97
        if pair_matrix[a][b] == 0:
            pair_matrix[a][b] = 1
            first_letters[a].append(letter_pair)
            last_letters[b].append(letter_pair)
        else:
            return 0
        
    # Ensure that (x, a) (y, a) dont exist
    for i in xrange(len(first_letters)):
        n = len(first_letters[i])
        n -= pair_matrix[i][i]
        if n > 1:
            return 0
        
    for i in xrange(len(last_letters)):
        n = len(last_letters[i])
        n -= pair_matrix[i][i]
        if n > 1:
            return 0
    
    # Combine ab bb bc -> ac
    i = 0
    while i < len(letter_pairs):
        letter_pair = letter_pairs[i]
        
        x = letter_pair[0]
        y = letter_pair[1]
        
        if x == y:
            i += 1
            continue
        
        a = ord(x) - 97
        b = ord(y) - 97
        if len(first_letters[b]):
            if pair_matrix[b][b]:
                pair_matrix[b][b] = 0
                first_letters[b].remove((y, y))
                last_letters[b].remove((y, y))
                
            if len(first_letters[b]):
                z = first_letters[b][0][1]
                c = ord(z) - 97
                
                pair_matrix[a][b] = 0
                first_letters[a].remove((x, y))
                last_letters[b].remove((x, y))
                letter_pairs.remove((x, y))
                
                pair_matrix[b][c] = 0
                first_letters[b].remove((y, z))
                last_letters[c].remove((y, z))
                letter_pairs.remove((y, z))
                
                if a == c:
                    return 0
                pair_matrix[a][c] = 1
                first_letters[a].append((x, z))
                last_letters[c].append((x, z))
                letter_pairs.append((x, z))
            i = 0
        else:
            i += 1
    
    # Ensure that (x, a) (y, a) dont exist
    for i in xrange(len(first_letters)):
        n = len(first_letters[i])
        n -= pair_matrix[i][i]
        if n > 1:
            return 0
        
    for i in xrange(len(last_letters)):
        n = len(last_letters[i])
        n -= pair_matrix[i][i]
        if n > 1:
            return 0
            
    multiplier *= factorial(sum(sum(x) for x in pair_matrix))
    
    return multiplier


def main():
    output = ''
    result = ''
    with open('B-small-attempt0.in') as f:
        cases = int(f.readline()[:-1])
        for case in range(cases):
            f.readline()
            line = f.readline()[:-1]
            trains = line.split(' ')
            result = solve(trains)
            
            output += 'Case #%s: %s\n' % (case + 1, result)

    with open('B-small-attempt0.out', 'w') as f:
        f.write(output)

main()