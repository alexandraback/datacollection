f = open('C-small-attempt0.in', 'r')
g = open('output', 'w')

num_cases = int(f.readline().replace('\n', ''))
counter = 0

while counter < num_cases:
	n, m = [int(x) for x in f.readline().replace('\n', '').split(' ')]
	n_line = [int(x) for x in f.readline().replace('\n', '').split(' ')]
	m_line = [int(x) for x in f.readline().replace('\n', '').split(' ')]
	
	n_tups = []
	m_tups = []
	for i in xrange(len(n_line) / 2):
		n_tups.append((n_line[2*i], n_line[2*i+1]))
	for i in xrange(len(m_line) / 2):
		m_tups.append((m_line[2*i], m_line[2*i+1]))
	
	row = [0] * n
	new_row = []
	for i in xrange(m):
		flag = True
		for j in xrange(n):
			entry = row[j]
			if j > 0:
				temp = new_row[j-1]
				if flag and n_tups[j][1] == m_tups[i][1]:
					temp += min(n_tups[j][0], m_tups[i][0])
					flag = False
				elif  n_tups[j][1] == m_tups[i][1]:
					temp = max(temp, min(n_tups[j][0], m_tups[i][0]))
				entry = max(entry, temp)
			elif n_tups[j][1] == m_tups[i][1]:
				entry += min(n_tups[j][0], m_tups[i][0])
				flag = False
			new_row.append(entry)
			
			'''
			entry = row[j]
			if n_tups[j][1] == m_tups[i][1]:
				entry += min(n_tups[j][0], m_tups[i][0])
				new_indices 
			if j > 0:
				entry = max(entry, new_row[j-1])
			new_row.append(entry)
			'''
			
			
		row = new_row[:]
		#print row
		new_row = []
	answer = row[n-1]
	g.write("Case #" + str(counter+1) + ": " + str(answer) + '\n')
	counter += 1

f.close()
g.close()