def merge(left, right):
    result = []
    left_idx, right_idx = 0, 0
    while left_idx < len(left) and right_idx < len(right):
        # change the direction of this comparison to change the direction of the sort
        if left[left_idx] >= right[right_idx]:
            result.append(left[left_idx])
            left_idx += 1
        else:
            result.append(right[right_idx])
            right_idx += 1
 
    if left:
        result.extend(left[left_idx:])
    if right:
        result.extend(right[right_idx:])
    return result
	
def merge_sort(m):
    if len(m) <= 1:
        return m
 
    middle = len(m) / 2
    left = m[:middle]
    right = m[middle:]
 
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))
	

f=open('temp.txt','rb')
g=open('submit.txt','wb')
for i in range(int(f.readline().strip())):
	g.write('Case #' + str(i+1) +': ')
	print i+1,':'
	f.readline()
	n = merge_sort(map(float,f.readline().strip().split()))
	k = merge_sort(map(float,f.readline().strip().split()))
	nn = n
	kk = k
	ind = 0
	while ind<len(n):
		if n[ind]>k[ind]:
			ind+=1
		else:
			n=n[:-1]
			k=k[1:]
	g.write(str(len(n)) + ' ')
	print len(n)
	win = 0
	n=nn
	k=kk
	while n:
		if n[-1]>k[0]:
			win+=1
			k=k[:-1]
			n=n[:-1]
		else:
			j= len(k)-1
			while n[-1] > k[j]:
				j-=1
			n=n[:-1]
			k=k[:j]+k[j+1:]
	print win
	g.write(str(win) + '\n')
	
	