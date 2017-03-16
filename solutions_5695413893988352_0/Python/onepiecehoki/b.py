
"""
state:
    1 --> c > j
    0 --> c == j
    -1 --> c < j
"""
def dfs(cur_c, cur_j, pos, state):
    result = {}
    if pos == len(cur_c):
        result['c'] = ''.join(cur_c)
        result['j'] = ''.join(cur_j)
        return result['c'], result['j'], abs(int(result['c']) - int(result['j'])) 
    result['c'] = ''
    result['j'] = ''
    def update_result(temp_c, temp_j, temp_min_diff, result):
        if not 'min_diff' in result or temp_min_diff < result['min_diff'] or (temp_min_diff == result['min_diff'] and temp_c < result['c']) or (temp_min_diff == result['min_diff'] and temp_c == result['c'] and temp_j < result['j']):
            result['c'] = temp_c[:]
            result['j'] = temp_j[:]
            result['min_diff'] = temp_min_diff
            if result['min_diff'] == 0:
                return result['c'], result['j'], result['min_diff']
        return None
    #print(' '*pos, cur_c, cur_j, pos, state)
    if state == 0:
        if cur_c[pos] == '?':
            if cur_j[pos] == '?':
                # try cur_c == cur_j
                cur_c[pos] = '0'
                cur_j[pos] = '0'
                temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 0)
                if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                    return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
                cur_j[pos] = '?'
                # try cur_c < cur_j
                cur_c[pos] = '0'
                cur_j[pos] = '1'
                temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, -1)
                if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                    return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
                cur_j[pos] = '?'
                # try cur_c > cur_j
                cur_c[pos] = '1'
                cur_j[pos] = '0'
                temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 1)
                if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                    return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
                cur_j[pos] = '?'
            else:
                # try cur_c == cur_j
                cur_c[pos] = cur_j[pos]
                temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 0)
                if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                    return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
                # try cur_c < cur_j
                if cur_j[pos] != '0':
                    cur_c[pos] = chr( ord(cur_j[pos]) -1)
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, -1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
                # try cur_c > cur_j
                if cur_j[pos] != '9':
                    cur_c[pos] = chr( ord(cur_j[pos]) + 1)
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                cur_c[pos] = '?'
        else:
            if cur_j[pos] == '?':
                # try cur_c == cur_j
                cur_j[pos] = cur_c[pos]
                temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 0)
                if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                    return result['c'], result['j'], result['min_diff']
                cur_j[pos] = '?'
                # try cur_c < cur_j
                if cur_c[pos] != '9':
                    cur_j[pos] = chr( ord(cur_c[pos]) + 1)
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, -1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                cur_j[pos] = '?'
                # try cur_c > cur_j
                if cur_c[pos] != '0':
                    cur_j[pos] = chr( ord(cur_c[pos]) - 1)
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                cur_j[pos] = '?'
            else:
                if ord(cur_c[pos]) == ord(cur_j[pos]):
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 0)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                elif ord(cur_c[pos]) < ord(cur_j[pos]):
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, -1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
                elif ord(cur_c[pos]) > ord(cur_j[pos]):
                    temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 1)
                    if update_result(temp_c, temp_j, temp_min_diff, result) != None:
                        return result['c'], result['j'], result['min_diff']
    elif state == 1:
        old_c = cur_c[pos]
        old_j = cur_j[pos]
        if cur_c[pos] == '?':
            cur_c[pos] = '0'
        if cur_j[pos] == '?':
            cur_j[pos] = '9'
        temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, 1)
        if update_result(temp_c, temp_j, temp_min_diff, result) != None:
            return result['c'], result['j'], result['min_diff']
        cur_c[pos] = old_c
        cur_j[pos] = old_j
    elif state == -1:
        old_c = cur_c[pos]
        old_j = cur_j[pos]
        if cur_c[pos] == '?':
            cur_c[pos] = '9'
        if cur_j[pos] == '?':
            cur_j[pos] = '0'
        temp_c, temp_j, temp_min_diff = dfs(cur_c, cur_j, pos+1, -1)
        if update_result(temp_c, temp_j, temp_min_diff, result) != None:
            return result['c'], result['j'], result['min_diff']
        cur_c[pos] = old_c
        cur_j[pos] = old_j
    return result['c'], result['j'], result['min_diff']








                



T = int(raw_input())
for t in xrange(1, T+1):
    C, J = tuple(raw_input().split())
    C_list = list(C)
    J_list = list(J)
    result = {}
    result['c'], result['j'], result['min_diff'] = dfs(C_list, J_list, 0, 0)
    print("Case #%d: %s %s" %(t, result['c'], result['j']))
