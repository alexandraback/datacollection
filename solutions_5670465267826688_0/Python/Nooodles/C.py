### Google code jam 2015
### Qualification round
### Problem B: Infinite house of pancakes

def ijk(first, second):
    if first == '1':
        return second;

    # now have i,j,k products
    if (first == second):
        return '-1';
    if (first == 'i') and (second == 'j'):
        return 'k';
    if (first == 'j') and (second == 'k'):
        return 'i';
    if (first == 'k') and (second == 'i'):
        return 'j';
    
    if (first == 'k') and (second == 'j'):
        return '-i';
    if (first == 'i') and (second == 'k'):
        return '-j';
    if (first == 'j') and (second == 'i'):
        return '-k';
    
def Prod(one, two):
    negatives = 0;
    if one[0] == '-':
        one = one[1:];
        negatives += 1;
    if two[0] == '-':
        two = two[1:];
        negatives += 1;
    result = ijk(one, two);
    if (negatives == 1):
        if result[0] == '-':
            return result[1:];
        else:
            return '-'+result;
    return result;

def Eval(substring):
    if len(substring) == 0:
        return '1';

    value = substring[0];
    for i in range(1, len(substring)):
        value = Prod(value,substring[i]);
    return value;

def FindSubstring(fullstring, target):
    value = '1';
    for i in range(len(fullstring)):
        value = Prod(value, fullstring[i]);
        if value == target:
            return i+1;
    return -1;
    


Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),
    [L, X] = map(int, raw_input().split());
    data = raw_input().split()[0];

    FullData = data*X;
    Answer = "NO";                  # Default

    if Eval(FullData) == '-1':      # Requirement
        part1 = FindSubstring(FullData, 'i');
        if (part1 > 0):
            part2 = FindSubstring(FullData[part1:], 'j');
            if (part2 > 0):
                Answer = "YES";

    print Answer;
    
