UNKNOWN = -1

def find(list, el):
	for i in range(len(list)):
		if list[i] == el:
			return i
	return -1

def save(i, links, answers, answer):
	while answers[i] == UNKNOWN:
		answers[i] = answer
		i = links[i]

def tryit(i, links, answers):
	if answers[i] != UNKNOWN:
		return

	cur = i
	visited = set()
	visited_list = []
	while True:
		visited.add(cur)
		visited_list.append(cur)
		cur = links[cur]

		if (answers[cur] != UNKNOWN):
			save(i, links, answers, answers[cur])
			return

		if (cur in visited):
			index = find(visited_list, cur)
			answer = len(visited_list) - index
			save(i, links, answers, answer)
			return 

def find_smallest_length(links):
	N = len(links)
	answers = [UNKNOWN]*N
	for i in range(N):
		tryit(i, links, answers)

	# print (answers)
	return max(answers)

def dfs(ilinks, v):
	if len(ilinks[v]) == 0:
		return 1
	else: 
		return 1 + max(dfs(ilinks, i) for  i in ilinks[v])


def find_longest_path_to_pair(links):
	N = len(links)
	paired = []
	for i in range(N):
		if links[links[i]] == i:
			paired.append(i)

	ilinks = [[] for i in range(N)]
	for i in range(N):
		if links[links[i]] != i:
			ilinks[links[i]].append(i)

	answer = sum([0] + [(dfs(ilinks, p) + dfs(ilinks, links[p])) for p in paired]) // 2
	# print(paired, [(p, dfs(ilinks, p), (dfs(ilinks, p) + dfs(ilinks, links[p]))) for p in paired])
	return answer




n = int(input())


for i in range(n):
	N = int(input())
	links = list(map(int, input().split()))
	links = [(i - 1) for i in links]

	print(("Case #%d: " % (i+1)) + str(max(find_smallest_length(links), find_longest_path_to_pair(links)))) #i