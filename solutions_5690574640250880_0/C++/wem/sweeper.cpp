#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin>>t;
	
	for(int ti = 0; ti < t; ti++)
	{
		int r, c, m;
		cin>>r>>c>>m;
		
		int mtmp = m;
		
		char** data = new char*[c];
		for(int i = 0; i < c; i++)
		{
			data[i] = new char[r];
			for(int j = 0; j < r; j++)
				data[i][j] = '.';
		}
		bool ok = true;
		
		if(m == r * c - 1)
		{	
			for(int i = 0; i < c; i++)
			{
				data[i] = new char[r];
				for(int j = 0; j < r; j++)
					data[i][j] = '*';
			}
			data[0][0] = 'c';
		} else
		{
		
			data[0][0] = 'c';
			if( c > r)
			{
				bool escape = false;
				for(int i = c-1;i >= r; i--)
				{
					if(escape) break;
				
					for(int j = r-1; j >=0; j--)
					{
						if(j == 1 && m ==1)
						{
						
							//escape = true;
							break;
						}
					
						if(m > 0)
						{
							m--;
							data[i][j] = '*';
						}
						if(m <= 0) 
						{
							escape = true;
							break;
						}
					}
				}
				//m -= (c-r) * r;
				//cout<<": "<<m<<endl;
			} else
			{
			
				bool escape = false;
				for(int j = r-1;j >= c; j--)
				{
					if(escape) break;
					for(int i = c-1; i >= 0; i--)
					{
						if(i == 1 && m ==1)
						{

							//escape = true;
							break;
						}
					
						if(m > 0)
						{
							m--;
							data[i][j] = '*';
						}
						if(m <= 0) 
						{
							escape = true;
							break;
						}
					}
				}
				//m -= (r-c) * c;
				//cout<<": "<<m<<endl;
			}
		
		
			//cout<<"1) "<<m<<endl;
		
			int size = min(r, c);
		
			bool escape = false;
			for(int j = size-1; j >=2; j--)
			{
				if(escape) break;
			
				for(int i = size-1; i >=0; i--)
				{
					if(i == 1 && m ==1)
					{
						//escape = true;
						break;
					}
					if(m > 0)
					{
						data[i][j] = '*';
						m--;
					}
					if(m <= 0) 
					{
						escape = true;
						break;
					}
				}
			}
		
		
			if(m % 2 == 0)
			{
				ok = true;
			
				for(int i = size-1; i >=2; i--)
				{
					if(m > 0)
					{
						data[i][0] = '*';
						data[i][1] = '*';
						m -=2;
					} else break;
				}
			
				if(m != 0) ok = false;
			} else
			{
				ok = false;
			}
		
		}
		
		if(ok == false && r > 3 && c > 3)
		{
		
		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		for(int i = 0; i < c; i++)
		{
			for(int j = 0; j < r; j++)
				data[i][j] = '.';
		}
		
		ok = true;
		m = mtmp;
		
		data[1][1] = 'c';
		
		
		if( c > r)
		{
			bool escape = false;
			for(int i = c-1;i >= r; i--)
			{
				if(escape) break;
			
				for(int j = r-1; j >=0; j--)
				{
					if(j >2 || i > 2)
					{
						if(j == 1 && m ==1)
						{

							break;
						}
					
						if(m > 0)
						{
							m--;
							data[i][j] = '*';
						}
						if(m <= 0) 
						{
							escape = true;
							break;
						}
					}
				}
			}
				//m -= (c-r) * r;
				//cout<<": "<<m<<endl;
			} else if( c < r)
			{
			
				bool escape = false;
				for(int j = r-1;j >= c; j--)
				{
					if(escape) break;
					for(int i = c-1; i >= 0; i--)
					{
						if(j >2 || i > 2)
						{
							if(i == 1 && m ==1)
							{

								//escape = true;
								break;
							}
					
							if(m > 0)
							{
								m--;
								data[i][j] = '*';
							}
							if(m <= 0) 
							{
								escape = true;
								break;
							}
						}
					}
				}
				//m -= (r-c) * c;
				//cout<<": "<<m<<endl;
			}
		
		
			//cout<<"1) "<<m<<endl;
		
			int size = min(r, c);
		
			bool escape = false;
			for(int j = size-1; j >2; j--)
			{
				if(escape) break;
			
				for(int i = size-1; i >=0; i--)
				{
					//if(j >2 || i > 2)
					{
						if(i == 1 && m ==1)
						{
							//escape = true;
							break;
						}
						if(m > 0)
						{
							data[i][j] = '*';
							m--;
						}
						if(m <= 0) 
						{
							escape = true;
							break;
						}
					}
				}
			}
		
		
			//if(m % 3 == 0)
			//{
				ok = true;
			
				for(int i = size-1; i >=2; i--)
				{
					if(i > 2)
					{
						if(m == 1)
						{
							data[i][2] = '*';
							m -=1;
						} else
						if(m > 2)
						{
							data[i][0] = '*';
							data[i][1] = '*';
							data[i][2] = '*';
							m -=3;
						} else break;
					}
				}
			
				if(m != 0) ok = false;
			//} else
			//{
			//	ok = false;
			//}
		
			//cout<<"$: "<<m<<endl;
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		////////////////////////////////////////////////////////////////////////
		////////////////////////////////////////////////////////////////////////
		
		}
		
		cout<<"Case #"<<ti+1<<": "<<endl;
		if(!ok)
		{
			cout<<"Impossible"<<endl;
		}
		else
		{
			
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
					cout<<data[j][i];
				cout<<endl;
			}
		}
	}

}
