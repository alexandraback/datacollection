package com.my;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Main {

	public static void main(String[] args) {

		Dancing d = new Dancing();

		d.danc();

	}
}

class Dancing {

	public void danc()	{

		try {

			String fileLocation = "C://Training//Google//DancingWiththeGooglers//src//com//my//smallInput.txt";

			BufferedReader reader = getInputFile(fileLocation);

			String line = reader.readLine();

			int count=1;
			while ( ( line = reader.readLine()) != null	 ) {

				String inputs[] = line.split(" " );
				
				int totalParticipant = Integer.parseInt(inputs[0]);
				int surprising = Integer.parseInt(inputs[1]);
				int inResult = Integer.parseInt(inputs[2]);
				List list = new ArrayList();

				for( int i=0;i<totalParticipant;++i)	{

					int score = Integer.parseInt(inputs[3+i]);
					list.add(triplet(score,inResult));
				}

				int totalCount = 0 ;

				for( int i=0; i<list.size();++i	)	{
					if( totalCount == surprising)
						break;
					List l = (List )list.get(i);
					if( !((Boolean)l.get(0)) &&  (Boolean)l.get(1))	{
						l.set(1, false);
						l.set(0, false);
						++totalCount;

					}
				}

				if( totalCount < surprising)	{
					for( int i=0; i<list.size();++i	)	{
						List l = (List )list.get(i);
						if( (Boolean)l.get(1))	{
							l.set(1, false);
							l.set(0, false);
							++totalCount;
							if( totalCount == surprising)
								break;
						}
					}
				}
				for( int i=0; i<list.size();++i	)	{
					List l = (List )list.get(i);

					if( ((Boolean)l.get(0)) )	{
						++totalCount;
					}
				}
				System.out.print("Case #" + count + ": ");
				++count;
				System.out.println(totalCount);
			}



		}
		catch (Exception e) {
			// TODO: handle exception
		}
	}


	public BufferedReader getInputFile(String fileLocation)	throws Exception{

		BufferedReader reader = new BufferedReader(new FileReader(new File(fileLocation)));

		return reader;
	}

	public List triplet(int score, int inResult)	{

		List<String> surpriseList = new ArrayList<String>();
		java.util.List<String> list = new ArrayList<String>();

		try {

			int mid = score/3;

			for( int i=0; i<3;++i)	{
				for( int j=0; j<3; ++j)	{
					for( int k=0; k<3; ++k)	{
						int total = (mid+i) + (mid+j) + (mid+k);
						if( total == score){
							if( (mid+i) >= inResult ||  (mid+j) >= inResult ||  (mid+k) >= inResult )	{
								String str = sort((mid+i),(mid+j),(mid+k));
								if( isSurprise((mid+i),(mid+j),(mid+k)))	{
									if( !surpriseList.contains(str))
										surpriseList.add(str);
								}
								else
									if( !list.contains(str))
										list.add(str);
							}
						}		
					}
				}
			}
			if( mid >= 1)	{
				mid--;
				for( int i=0; i<3;++i)	{
					for( int j=0; j<3; ++j)	{
						for( int k=0; k<3; ++k)	{
							int total = (mid+i) + (mid+j) + (mid+k);
							if( total == score){
								if( (mid+i) >= inResult ||  (mid+j) >= inResult ||  (mid+k) >= inResult )	{
									String str = sort((mid+i),(mid+j),(mid+k));
									if( isSurprise((mid+i),(mid+j),(mid+k)))	{
										if( !surpriseList.contains(str))
											surpriseList.add(str);
									}
									else
										if( !list.contains(str))
											list.add(str);
								}
							}
						}
					}
				}
			}

		} catch (Exception e) {
			// TODO: handle exception
		}

		List  returnList = new ArrayList ();

		if( list.size() > 0)
			returnList.add(true);
		else
			returnList.add(false);
		if(surpriseList.size() >0 )
			returnList.add(true);
		else
			returnList.add(false);

		return returnList;
	}


	public String sort(int num1, int num2, int num3)	throws Exception{

		List<Integer> list = new ArrayList<Integer>();
		list.add(num1);
		list.add(num2);
		list.add(num3);
		Collections.sort(list);

		String s = "";

		for( int i =0; i<list.size();++i)	{
			s = s + list.get(i) + " ";
		}

		return s;
	}

	public boolean isSurprise(int num1, int num2, int num3)	{

		if( num1-num2 == 2 || num1-num3 == 2 || num2-num1 == 2 || num2-num3 == 2 || num3-num1 == 2 || num3-num2 == 2 )
			return true;

		return false;
	}
}
